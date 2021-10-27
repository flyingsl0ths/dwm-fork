#!/bin/sh

kill_existing() {
    instance_pid="$(pgrep -fo "/bin/sh /home/flyingsl0ths/.dwm/status_bar.sh")"

    if [ "$instance_pid" != "$$" ]; then
        kill -KILL "$instance_pid"
    fi
}

status_bar() {
    wifi_connection="[  $(nmcli -t -f name connection show --active | awk '{print $1}')]"

    #ram_usage="[R: $(free -h --si | grep Mem | awk '{print ($3)}')]"

    todays_date="[  $(date +"%b %d, %Y %a %I:%M%p")]"

    battery_level="[  $(cat /sys/class/power_supply/BAT1/capacity)%]"

    volume_level="[  $(pamixer --get-volume-human)]"

    xsetroot -name "$wifi_connection | $todays_date | $battery_level | $volume_level"
}

kill_existing

while true; do
    status_bar
    sleep 1
done
